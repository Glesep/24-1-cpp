int count = 0, limit = 100;
for (int i=1; i<=limit; i++) {                                  // 100번 반복                   i

    for (int j=i+1; j<=limit; j++) {                            // 99번 반복                    i+1

        for (int k=j+1; k<=limit; k++) {                        // 98번 반복                    i+2                 결국 98번 반복함

            if ((i + j + k) % 10 == 0)                          // i + i+1 + i+2 % 10 == 3i + 3을 10으로 나눈 나머지가 0이 될 때 == 10의 배수일 때
                count++;
        }
    }   
}
cout << count << end

