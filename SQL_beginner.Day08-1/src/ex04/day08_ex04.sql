-- s1
SHOW TRANSACTION ISOLATION LEVEL;
BEGIN;
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
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

-- s2
SHOW TRANSACTION ISOLATION LEVEL;
BEGIN;
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
UPDATE pizzeria
SET rating = 3.0
WHERE name = 'Pizza Hut';
COMMIT;
SELECT rating
FROM pizzeria
WHERE name = 'Pizza Hut';