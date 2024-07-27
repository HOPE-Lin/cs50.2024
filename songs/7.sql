SELECT AVG(energy)
FROM songs
JOIN artists ON artists.id = songs.artist_id
WHERE song.name = 'Drake';
