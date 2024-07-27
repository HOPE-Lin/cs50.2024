-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT id, description
FROM crime_scene_reports
WHERE year = 2023
  AND month = 'July'
  AND day = 28
  AND street = 'Humphrey Street';
