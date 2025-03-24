WITH Dates AS (SELECT generate_series(DATE '2022-01-01', DATE '2022-01-10', '1 day') AS visit_date)
SELECT d.visit_date::date AS missing_date
FROM Dates AS d
         LEFT JOIN person_visits AS pv ON d.visit_date = pv.visit_date
    AND (pv.person_id = 1 OR pv.person_id = 2)
WHERE pv.person_id IS NULL
ORDER BY d.visit_date;