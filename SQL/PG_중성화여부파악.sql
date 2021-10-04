SELECT ANIMAL_ID, NAME, (CASE SEX_UPON_INTAKE
                            WHEN 'Intact' THEN 'X'
                            WHEN 'Intact Female' THEN 'X'
                            ELSE 'O' END)
FROM ANIMAL_INS
