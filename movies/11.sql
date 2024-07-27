SELECT title
FROM movies
WHERE id IN
(
    SELECT directors.movie_id
    FROM directors
    JOIN ratings ON directors.movie_id = ratings.movie_id
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = 'Chadwick Boseman'
    )
    ORDER BY ratings.rating
    LIMIT 5
);
