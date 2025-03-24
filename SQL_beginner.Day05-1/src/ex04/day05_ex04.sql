CREATE INDEX idx_menu_unique ON menu (pizzeria_id, pizza_name);

SET enable_seqscan TO OFF;
EXPLAIN (ANALYZE) --BUFFERS
SELECT pizzeria_id, pizza_name
FROM menu;
SET enable_seqscan TO ON;
