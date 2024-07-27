-- Keep a log of any SQL queries you execute as you solve the mystery.
--找到犯罪
SELECT id，description
FROM crime_scene_reports
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND street = 'Humphrey Street'
  AND  description LIKE '%CS50%';
