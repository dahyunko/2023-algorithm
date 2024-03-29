-- 코드를 작성해주세요
with A as (
    select max(SIZE_OF_COLONY) as max_size , YEAR(DIFFERENTIATION_DATE) as year
    from ECOLI_DATA
    group by year
)

select YEAR(a.DIFFERENTIATION_DATE) as YEAR, (b.max_size - a.SIZE_OF_COLONY) as YEAR_DEV, a.ID
from ECOLI_DATA as a join A as b on YEAR(a.DIFFERENTIATION_DATE) = b.year
order by year, YEAR_DEV;