SELECT * FROM employees as e
where (select id from clients as c
		where e.id = c.id limit 1) is null;