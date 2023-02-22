-- 코드를 입력하세요
SELECT A.PRODUCT_CODE, A.PRICE * SUM(B.SALES_AMOUNT) AS SALES
FROM PRODUCT A INNER JOIN OFFLINE_SALE B ON A.PRODUCT_ID = B.PRODUCT_ID
GROUP BY B.PRODUCT_ID
ORDER BY SALES DESC, A.PRODUCT_CODE ASC;