import random

# Function to generate test data and save it to a file
def generate_test_data():
    sizes = [10, 100, 500, 1000, 10000]
    conditions = ['random', 'reversed', 'sorted']
    
    for size in sizes:
        for condition in conditions:
            if condition == 'random':
                arr = [random.randint(0, 10000) for _ in range(size)]
            elif condition == 'reversed':
                arr = list(range(size, 0, -1))
            elif condition == 'sorted':
                arr = list(range(size))
            
            filename = f"data_{condition}_{size}.txt"
            with open(filename, 'w') as f:
                for num in arr:
                    f.write(f"{num}\n")
            print(f"Generated {filename}")

# Generate test data
generate_test_data()
