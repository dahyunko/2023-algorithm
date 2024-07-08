WITH HISTORY AS (
    SELECT A.APNT_NO, P.PT_NAME, P.PT_NO, A.MCDP_CD, A.MDDR_ID, A.APNT_YMD
    FROM PATIENT AS P JOIN APPOINTMENT AS A ON(P.PT_NO = A.PT_NO)
    WHERE A.APNT_YMD LIKE "%2022-04-13%"
    AND A.APNT_CNCL_YMD IS NULL
    AND A.MCDP_CD = 'CS'
)

SELECT H.APNT_NO, H.PT_NAME, H.PT_NO, H.MCDP_CD, D.DR_NAME, H.APNT_YMD 
FROM HISTORY AS H JOIN DOCTOR AS D ON(H.MDDR_ID = D.DR_ID)
ORDER BY H.APNT_YMD;