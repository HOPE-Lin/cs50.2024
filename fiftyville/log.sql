-- Keep a log of any SQL queries you execute as you solve the mystery.
--找到犯罪现场描述
SELECT description
FROM crime_scene_reports
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND street = 'Humphrey Street'
  AND  description LIKE '%CS50%';
  --了解到发生时间：10.15am，三个目击者，详细地点是bakery
SELECT transcript,name
FROM interviews
WHERE year = 2023
  AND month = 7
  AND day = 28;
