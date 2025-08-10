package com.example.menu_driven_bg_color;

import com.example.menu_driven_bg_color.R;
import androidx.appcompat.app.AppCompatActivity;
import android.graphics.Color;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.RelativeLayout;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    RelativeLayout rootLayout;
    TextView tvMessage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        rootLayout = findViewById(R.id.rootLayout);
        tvMessage = findViewById(R.id.tvMessage);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.color_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int itemId = item.getItemId();

        if (itemId == R.id.menu_red) {
            rootLayout.setBackgroundColor(Color.RED);
            tvMessage.setText("Background: Red");
            return true;
        } else if (itemId == R.id.menu_green) {
            rootLayout.setBackgroundColor(Color.GREEN);
            tvMessage.setText("Background: Green");
            return true;
        } else if (itemId == R.id.menu_blue) {
            rootLayout.setBackgroundColor(Color.BLUE);
            tvMessage.setText("Background: Blue");
            return true;
        } else if (itemId == R.id.menu_yellow) {
            rootLayout.setBackgroundColor(Color.YELLOW);
            tvMessage.setText("Background: Yellow");
            return true;
        } else {
            return super.onOptionsItemSelected(item);
        }
    }

}
