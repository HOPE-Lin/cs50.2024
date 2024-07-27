SELECT title
FROM movies
WHERE id IN
(
    SELECT stars.movie_id
    FROM stars
    JOIN ratings ON stars.movie_id = ratings.movie_id
    CASE
        WHEN rating = (SELECT MAX(rating) FROM ratings) THEN 1
        ELSE 0
    END AS ma_rat
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = 'Chadwick Boseman'
    )
    ORDER BY rating DESC
    LIMIT 5
);
