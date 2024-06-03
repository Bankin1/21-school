CREATE FUNCTION func_minimum(VARIADIC arr numeric[]) RETURNS numeric AS
$$
BEGIN
    RETURN (SELECT min(arrrr) FROM unnest(arr) as arrrr);
END;
$$ LANGUAGE plpgsql;

SELECT func_minimum(VARIADIC arr => ARRAY [10.0, -1.0, 5.0, 4.4]);