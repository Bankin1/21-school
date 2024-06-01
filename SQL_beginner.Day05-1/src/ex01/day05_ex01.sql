SET enable_seqscan TO OFF;
EXPLAIN (ANALYZE) --BUFFERS
SELECT pizza_name, pi.name AS pizzaria_name
FROM menu
         JOIN pizzeria AS pi ON menu.pizzeria_id = pi.id
ORDER BY 1;
SET enable_seqscan TO ON;