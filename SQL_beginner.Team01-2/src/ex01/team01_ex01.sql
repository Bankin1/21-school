insert into currency
values (100, 'EUR', 0.85, '2022-01-01 13:29');
insert into currency
values (100, 'EUR', 0.79, '2022-01-08 13:29');

SELECT DISTINCT COALESCE(u.name, 'not defined')                                            AS name,
                COALESCE(u.lastname, 'not defined')                                        AS lastname,
                cur.name                                                                   AS currency_name,
                cur.money * COALESCE(cur.less_date_rate_to_usd, cur.more_date_rate_to_usd) AS currency_in_usd
FROM (SELECT name,
             b.user_id,
             b.money,
             b.updated,
             (SELECT rate_to_usd
              FROM currency AS c
              WHERE b.currency_id = c.id
                AND b.updated > c.updated
              ORDER BY c.updated DESC
              LIMIT 1) AS less_date_rate_to_usd,
             (SELECT rate_to_usd
              FROM currency AS c
              WHERE b.currency_id = c.id
                AND b.updated < c.updated
              ORDER BY c.updated
              LIMIT 1) AS more_date_rate_to_usd
      FROM currency
               JOIN public.balance b on currency.id = b.currency_id) AS cur
         LEFT JOIN "user" AS u ON cur.user_id = u.id
ORDER BY 1 DESC, 2, 3;
