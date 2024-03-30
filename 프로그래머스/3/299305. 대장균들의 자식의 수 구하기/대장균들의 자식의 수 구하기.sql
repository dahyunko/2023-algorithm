-- 코드를 작성해주세요
select distinct a.id, count(b.PARENT_ID) as CHILD_COUNT
from ecoli_data as a left join ecoli_data as b on(a.id = b.parent_id)
group by a.id
order by a.id;