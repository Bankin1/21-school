INSERT INTO person_order (id, person_id, menu_id, order_date)
VALUES (generate_series((SELECT MAX(id) FROM person_order) + 1,
                        (SELECT MAX(id) FROM person_order) + (SELECT MAX(id) FROM person)),
        (generate_series((SELECT MIN(id) FROM person), (SELECT MAX(id) FROM person))),
        (SELECT id FROM menu WHERE pizza_name = 'Greek pizza'),
        '2022-02-25');

-- SELECT * FROM generate_series(2,4);
-- INSERT INTO person_order (id, person_id, menu_id, order_date)
-- VALUES ((SELECT MAX(id) + 1 FROM person_order),
--         (SELECT id FROM person WHERE name = 'Denis'),
--         (SELECT id FROM menu WHERE pizza_name = 'Sicilian pizza'),
--         '2022-02-24');