def eval_postfix(expression):
    stack = []
    
    for e in expression:
        try:
            num = float(e)
            stack.append(num)
        except ValueError:
            if len(stack) < 2:
                print("Error: Not enough operands.")
                return

            op1 = stack.pop()
            op2 = stack.pop()

            if e == "^" or e == "$":
                result = op2 ** op1
            elif e == "+":
                result = op2 + op1
            elif e == "-":
                result = op2 - op1
            elif e == "*":
                result = op2 * op1
            elif e == "/":
                if op1 == 0:
                    print("Error: Division by zero.")
                    return
                result = op2 / op1
            else:
                print(f"Error: Unknown operator '{e}'")
                return

            stack.append(result)

    if len(stack) != 1:
        print("Error: Invalid postfix expression.")
    else:
        print(f"Result is {stack.pop()}")

expression = input("Enter the postfix expression each term separated by space: ")
eval_postfix(expression.split())
