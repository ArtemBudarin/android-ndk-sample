package ru.madbrains.ndksample

import android.widget.Toast

object SampleJniCalls {

    external fun initJni()
    external fun getRepository(): Repository?
    external fun getCommits(): ArrayList<Commit>?

    @JvmStatic
    fun showPoint(x: Int, y: Int) {
        println("point: x=$x y=$y")
    }

    @JvmStatic
    fun showToast(message: String) {
        Toast.makeText(App.instance, message, Toast.LENGTH_SHORT).show()
    }

}