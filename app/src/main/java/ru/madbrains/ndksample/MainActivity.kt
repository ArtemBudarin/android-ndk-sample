package ru.madbrains.ndksample

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    companion object {
        init {
            System.loadLibrary("native-lib")
        }
    }

    private external fun stringFromJNI(): String

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        SampleJniCalls.initJni()

        loadRepositoryButton.setOnClickListener {
            SampleJniCalls.getRepository()?.let { repository ->
                println()
            }
        }

        loadCommitsButton.setOnClickListener {
            SampleJniCalls.getCommits()?.let { commits ->
                println()
            }
        }
    }

}
