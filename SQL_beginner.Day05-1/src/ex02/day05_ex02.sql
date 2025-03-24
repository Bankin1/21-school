CREATE INDEX idx_person_name ON person (UPPER(name));
SET enable_seqscan TO OFF;
EXPLAIN (ANALYZE) --BUFFERS
SELECT name
FROM person
WHERE upper(name) = upper(name)
ORDER BY 1;
SET enable_seqscan TO ON;