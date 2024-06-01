-- WITH R(id) AS (SELECT person_id FROM person_visits WHERE visit_date = '2022-01-02'),
--      S(id) AS (SELECT person_id FROM person_visits WHERE visit_date = '2022-01-06')

CREATE VIEW v_symmetric_union AS
(
SELECT tru.person_id
FROM (SELECT person_id
      FROM person_visits
      WHERE visit_date = '2022-01-02'
      EXCEPT
      SELECT person_id
      FROM person_visits
      WHERE visit_date = '2022-01-06') AS tru
UNION
(SELECT person_id
 FROM person_visits
 WHERE visit_date = '2022-01-06'
 EXCEPT
 SELECT person_id
 FROM person_visits
 WHERE visit_date = '2022-01-02')
ORDER BY 1
    )
