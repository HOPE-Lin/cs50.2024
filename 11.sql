SELECT title
FROM movies
WHERE id IN
(
    SELECT stars.movie_id
    FROM stars
    JOIN ratings ON stars.movie_id = ratings.movie_id
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = 'Chadwick Boseman'
    )
    ORDER BY ratings.rating DESC
    LIMIT 5
);
