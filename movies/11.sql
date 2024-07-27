SELECT title
FROM movies
WHERE id IN
(
    SELECT movie_id
    FROM directors
    JOIN ratings ON people.id = ratings.movie_id
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = 'Chadwick Boseman'
    )
    ORDER BY 
)
