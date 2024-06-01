-- s1
BEGIN;

UPDATE pizzeria
SET rating = 1
WHERE id = 1;

UPDATE pizzeria
SET rating = 3
WHERE id = 2;

COMMIT;

-- s2
BEGIN;

UPDATE pizzeria
SET rating = 2
WHERE id = 2;

UPDATE pizzeria
SET rating = 4
WHERE id = 1;

COMMIT;