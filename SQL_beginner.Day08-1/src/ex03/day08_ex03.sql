-- s1
SHOW TRANSACTION ISOLATION LEVEL;
BEGIN;
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';
COMMIT;
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';

-- s1
SHOW TRANSACTION ISOLATION LEVEL;
BEGIN;
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
UPDATE pizzeria
SET rating = 3.6
WHERE name = 'Pizza Hut';
COMMIT;
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';