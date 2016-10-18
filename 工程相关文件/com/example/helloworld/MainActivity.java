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
	
	//����ԭ������ ����ΪString���� ��������ΪString
	private native String printJNI(String inputStr);

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Log.v("dufresne", printJNI("I am HelloWorld Activity"));
	}
}
