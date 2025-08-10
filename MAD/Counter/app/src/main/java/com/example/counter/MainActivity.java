package com.example.counter;

import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    TextView textViewCounter;
    Button buttonStart, buttonStop;
    int counter = 0;
    boolean isRunning = false;
    Handler handler = new Handler(Looper.getMainLooper());
    Thread counterThread;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textViewCounter = findViewById(R.id.textViewCounter);
        buttonStart = findViewById(R.id.buttonStart);
        buttonStop = findViewById(R.id.buttonStop);
        buttonStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (isRunning==false) {
                    isRunning = true;
                    startCounter();
                }
            }
        });

        buttonStop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                isRunning = false;
            }
        });
    }

    private void startCounter() {
        counterThread = new Thread(new Runnable() {
            @Override
            public void run() {
                while (isRunning==true){
                    counter++;
                    handler.post(new Runnable() {
                        @Override
                        public void run() {
                            textViewCounter.setText(String.valueOf(counter));
                        }
                    });
                    try {
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                }

            }
        });
        counterThread.start();
    }
}
