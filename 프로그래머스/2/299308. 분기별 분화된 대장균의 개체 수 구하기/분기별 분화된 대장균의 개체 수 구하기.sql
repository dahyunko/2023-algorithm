-- 코드를 작성해주세요
select case 
    when month(DIFFERENTIATION_DATE) between 1 and 3
    then "1Q"
    when month(DIFFERENTIATION_DATE) between 4 and 6
    then "2Q"
    when month(DIFFERENTIATION_DATE) between 7 and 9
    then "3Q"
    when month(DIFFERENTIATION_DATE) between 10 and 12
    then "4Q"
    end QUARTER
, count(id) as ECOLI_COUNT
from ECOLI_DATA
group by QUARTER
order by QUARTER;