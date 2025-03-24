CREATE VIEW v_price_with_discount AS
(
SELECT p.name, m.pizza_name, m.price, (m.price * 0.9)::int AS discount_price
FROM person_order AS po
         JOIN menu AS m ON po.menu_id = m.id
         JOIN person AS p ON p.id = po.person_id
ORDER BY 1, 2);
