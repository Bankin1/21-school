CREATE SEQUENCE seq_person_discounts START 1;
ALTER TABLE person_discounts
    ALTER COLUMN id SET DEFAULT nextval('seq_person_discounts') - 1;
-- ALTER TABLE person_discounts
--     ALTER COLUMN id SET DEFAULT nextval('seq_person_discounts');
SELECT SETVAL('seq_person_discounts', (SELECT count(id) + 1 FROM person_discounts));
-- insert into person_discounts(person_id, pizzeria_id) values (
--     2,
--     4
-- );
-- DELETE FROM person_discounts WHERE id = 16;
-- ALTER TABLE person_discounts ALTER COLUMN id DROP DEFAULT;
-- drop sequence seq_person_discounts;
