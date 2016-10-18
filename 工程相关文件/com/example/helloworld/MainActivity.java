package com.example.helloworld;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {
	
	static{
		System.loadLibrary("HelloWorldJni");
	}
	
	//声明原生函数 参数为String类型 返回类型为String
	private native String printJNI(String inputStr);

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Log.v("dufresne", printJNI("I am HelloWorld Activity"));
	}
}
