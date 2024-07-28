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
SELECT transcript
FROM interviews
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND transcript LIKE '%bakery%';
  --10.15am ——10.25am小偷开汽车逃走，
/*SELECT activity, license_plate
FROM bakery_security_logs
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND hour = 10
  AND minute = 15;
