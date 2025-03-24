-- s1
BEGIN;
UPDATE pizzeria
SET rating = 5
WHERE name = 'Pizza Hut';
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';
COMMIT;
-- s2
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';