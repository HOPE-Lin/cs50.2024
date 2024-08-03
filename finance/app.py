import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]
    purchases = db.execute("""SELECT symbol, SUM(shares) AS shares, price
                        FROM purchases WHERE user_id =?
                        GROUP BY symbol HAVING SUM(shares) > 0""", user_id)
    people = []
    total = 0
    for purchase in purchases:
        symbol = purchase["symbol"]
        shares = purchase["shares"]
        result = lookup(symbol)
        if not result:
            return apology("股票查询出错")
        price = result["price"]
        value = price * shares
        total = total + value
        price = usd(price)
        value = usd(value)
        people.append({
            "symbol": symbol,
            "share": shares,
            "price": price,
            "value" : value
        })
    user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
    gtotal = total + user_cash
    user_cash = usd(user_cash)
    gtotal = usd(gtotal)
    return render_template("index.html",people = people, total = gtotal, cash = user_cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("股票代码不能为空")
        result = lookup(symbol)
        if not result:
            return apology("股票不存在")
        shares = request.form.get("shares")
        if not shares or shares.isdigit() or int(shares) <= 0:
            return apology("股份数出现错误")
        shares = int(shares)
        price = result["price"]
        user_id = session["user_id"]
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
        total = shares *  price
        if total > user_cash:
            return apology("余额不足")
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?" , total, user_id)
        db.execute("INSERT INTO purchases (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)",
               user_id, symbol, shares, price)
        return redirect("/")
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
             return apology("股票代码不能为空")
        result = lookup(symbol)
        if result:
            return render_template("quoted.html",symbol=result["symbol"], price=result["price"])
        else:
            return apology("无法获得股票价格")
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")
    else:
        try:
            username = request.form.get("username")
            password = request.form.get("password")
            again = request.form.get("again")
            if not username or not password or not again:
                return apology("必须填写全部字段")
            if again != password:
                return apology("两次密码不一致")
            db.execute("INSERT INTO users(username, hash)  VALUES(?, ?)" ,
                username, generate_password_hash(password))
        except sqlite3.IntegrityError:
            return apology("重复名字")
        except Exception as e:
            return apology(f"出现错误:{e}")
    return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_id = session["user_id"]
    
    return apology("TODO")
