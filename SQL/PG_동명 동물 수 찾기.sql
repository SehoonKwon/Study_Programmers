select name, count(name)
from animal_ins
group by name #그룹으로 묶고 묶인 name 그룹 갯수를 카운트한다 
having count(name) >= 2
order by name

/*
select name, count(*)
from animal_ins
where count(name) >= 2
이런식으로는 풀 수 없다.
COUNT와 같은 집계함수(COUNT, AVG, SUM, MAX, MIN)를 써버리면
WHERE절에서 WHERE COUNT(NAME) >= 2 같은 WHERE절이 먹히지 않는다
WHERE절은 한 행마다 조건을 걸어 가져오는건데 COUNT(NAME)은 이미 묶어서 가져온 것이기 때문에 WHERE절이 통하지 않기 때문이다
*/
