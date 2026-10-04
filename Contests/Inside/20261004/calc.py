while True:
    try:
        print(exec(input()))
    except Exception as e:
        print(e)