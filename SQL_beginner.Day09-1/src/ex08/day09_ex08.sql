CREATE FUNCTION fnc_fibonacci(pstop integer DEFAULT 10)
    RETURNS setof integer
AS
$$
WITH RECURSIVE fibonacci(Num, Prev) AS (SELECT 0, 1
                                        UNION ALL
                                        SELECT fibonacci.Num + fibonacci.Prev, fibonacci.Num
                                        FROM fibonacci
                                        WHERE fibonacci.Num < pstop)
SELECT Num
FROM fibonacci
WHERE Num < pstop;
$$ LANGUAGE sql;

select *
from fnc_fibonacci(100);

select *
from fnc_fibonacci();

