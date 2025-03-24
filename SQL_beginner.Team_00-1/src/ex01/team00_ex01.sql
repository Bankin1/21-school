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
ORDER BY 1, 2;