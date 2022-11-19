salary = input("Enter your salary in TOMAN : ")



if salary > 35000000 :
    tax = 4440000 + (salary - 35000000) * 0.3

elif salary > 25000000 :
    tax = 2440000 + (salary - 25000000) * 0.2

elif salary > 15000000 :
    tax = 940000 + (salary - 15000000) * 0.15

elif salary > 5600000 :
    tax = (salary - 5600000) * 0.1

else:
    tax = 0



print(tax)