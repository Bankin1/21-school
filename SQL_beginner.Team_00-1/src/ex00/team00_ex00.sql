CREATE TABLE nodes
(
    point1 VARCHAR NOT NULL,
    point2 VARCHAR NOT NULL,
    cost   INT     NOT NULL
);

INSERT INTO nodes
VALUES ('a', 'b', 10),
       ('b', 'a', 10),
       ('b', 'c', 35),
       ('c', 'b', 35),
       ('a', 'c', 15),
       ('c', 'a', 15),
       ('a', 'd', 20),
       ('d', 'a', 20),
       ('b', 'd', 25),
       ('d', 'b', 25),
       ('d', 'c', 30),
       ('c', 'd', 30)
ORDER BY 1, 2;

WITH tab AS (WITH RECURSIVE search AS (SELECT point1,
                                              point2,
                                              cost,
                                              1              as level,
                                              array [point1] AS path,
                                              FALSE          AS cycle,
                                              array [cost]   AS costs
                                       FROM nodes
                                       WHERE point1 = 'a'

                                       UNION ALL

                                       SELECT nodes.point1,
                                              nodes.point2,
                                              nodes.cost + search.cost         as cost,
                                              search.level + 1                 as level,
                                              search.path || nodes.point1      AS path,
                                              nodes.point1 = ANY (search.path) AS cycle,
                                              search.costs || nodes.cost       AS costs
                                       FROM nodes
                                                INNER JOIN search ON search.point2 = nodes.point1 AND NOT cycle)


             select cost - costs[5] as total_cost,
                    path            as tour
             from search
             where level = 5
               and 'a' = ANY (path)
               and 'b' = ANY (path)
               and 'c' = ANY (path)
               and 'd' = ANY (path)
               and path[1] = path[5]
             order by cost, path)

SELECT DISTINCT *
FROM tab
WHERE total_cost = (SELECT MIN(total_cost) FROM tab)
ORDER BY 1, 2;
