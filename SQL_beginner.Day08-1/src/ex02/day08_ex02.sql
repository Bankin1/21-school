-- s1
SHOW TRANSACTION ISOLATION LEVEL;
BEGIN;
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';
UPDATE pizzeria
SET rating = 4
WHERE name = 'Pizza Hut';
COMMIT;
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';

-- s2
SHOW TRANSACTION ISOLATION LEVEL;
BEGIN;
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';
UPDATE pizzeria
SET rating = 3.6
WHERE name = 'Pizza Hut';
COMMIT;
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';