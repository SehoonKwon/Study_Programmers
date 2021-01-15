SELECT hour(datetime), count(datetime) #hour라는 문법이 있음. 시간만 뽑아내줌
from animal_outs
where hour(datetime) >= 9 and hour(datetime) <= 19 #9시부터 19시까지
group by hour(datetime) #시간대별로 묶기
order by hour(datetime) #시간대 순으로 정렬하기
