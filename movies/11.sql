SELECT title
FROM movies
WHERE id IN
(
    SELECT movie_id
    FROM directors
    JOIN ratings ON directors.movie_id = ratings.movie_id
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = 'Chadwick Boseman'
    )
    ORDER BY rating
    LIMIT 5
);
