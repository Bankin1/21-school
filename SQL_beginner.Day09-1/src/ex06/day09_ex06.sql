CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(pperson varchar DEFAULT 'Dmitriy',
                                                              pprice numeric DEFAULT 500,
                                                              pdate date DEFAULT '2022-01-08') RETURNS SETOF varchar AS
$$
BEGIN
    RETURN QUERY
        SELECT DISTINCT p2.name
        FROM person AS p
                 JOIN public.person_visits pv on p.id = pv.person_id
                 JOIN public.menu m on pv.pizzeria_id = m.pizzeria_id
                 JOIN public.pizzeria p2 on p2.id = m.pizzeria_id
        WHERE p.name = pperson
          AND pv.visit_date = pdate
          AND m.price < pprice;

END
$$ LANGUAGE plpgsql;


select *
from fnc_person_visits_and_eats_on_date(pprice := 800);

select *
from fnc_person_visits_and_eats_on_date(pperson := 'Anna', pprice := 1300, pdate := '2022-01-01');
