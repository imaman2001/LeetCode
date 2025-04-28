# Write your MySQL query statement below

SELECT Person.firstName, Person.lastName , Address.city , Address.state
FROM Person
LEFT JOIN Address ON Person.personId = Address.personId;


-- SELECT (to select the specify column)
-- FROM (the Table)
-- JOIN means to join two tables on the behalf of (Person.personId = Address.personId )
-- ON means to define the condition for the join