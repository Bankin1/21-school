SELECT order_date, CONCAT(name, ' (age:', age, ')') AS person_information
FROM person_order
NATURAL JOIN (SELECT id AS person_id, age, name FROM person) AS ppi
ORDER BY order_date, person_information