select c.customer_id,c.customer_name
from customers as c
join orders as o
on c.customer_id = o.customer_id
group by c.customer_id, c.customer_name
HAVING COUNT(CASE WHEN o.product_name = 'A' THEN 1 END) > 0
   AND COUNT(CASE WHEN o.product_name = 'B' THEN 1 END) > 0
   AND COUNT(CASE WHEN o.product_name = 'C' THEN 1 END) = 0
order by customer_name;
