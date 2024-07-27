SELECT title, rating
FROM movies
join ratings ON movies.id = ratings. movie_id
WHERE movies.year = 2010
ORDER BY rating DESC, title;
