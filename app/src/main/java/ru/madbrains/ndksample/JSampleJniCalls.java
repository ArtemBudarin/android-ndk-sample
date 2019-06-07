package ru.madbrains.ndksample;

import android.widget.Toast;

public class JSampleJniCalls {

    native public static void initJni();

    public static void showPoint(int x, int y) {
        System.out.println("point: x=" + x + " y=" + y);
    }

    public static void showToast(String message) {
        Toast.makeText(App.instance, message, Toast.LENGTH_SHORT).show();
    }

}
