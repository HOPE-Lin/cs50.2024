-- Keep a log of any SQL queries you execute as you solve the mystery.
--找到犯罪现场描述
/*SELECT description
FROM crime_scene_reports
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND street = 'Humphrey Street'
  AND  description LIKE '%CS50%';
  --了解到发生时间：10.15am，三个目击者，详细地点是bakery

  --了解目击者的叙述
SELECT transcript, name
FROM interviews
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND transcript LIKE '%bakery%';
  --10.15am ——10.25am小偷开汽车逃走；
  --在Eugene到达面包店之前，小偷在Leggett Street ATM 上取钱；
  --离开面包店时，打电话让同伙买29日最早的航班离开Fiftyville，电话持续不到一分钟

  --面包店停车场的监控录像，开车离开的人*/
SELECT name
FROM people
WHERE license_plate IN
(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2023
      AND month = 7
      AND day = 28
      AND hour = 10
      AND minute > 15 AND minute < 25
     AND activity = 'exit'
);

--小偷在Leggett Street ATM 上取钱取钱，在Eugene到达面包店之前；
SELECT name
FROM people
WHERE id IN
(
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2023
           AND month = 7
           AND day = 28
           AND atm_location = 'Leggett Street'
           AND transaction_type = 'withdraw'
    )
);

--离开面包店时，打电话，电话持续不到一分钟
SELECT caller, receiver
FROM phone_calls
WHERE year = 2023
    AND month = 7
    AND day = 28
    AND duration < 60
JOIN people.name ON  people.phone_number = phone_calls.caller
JOIN people.name ON  people.phone_number = phone_calls.receiver
