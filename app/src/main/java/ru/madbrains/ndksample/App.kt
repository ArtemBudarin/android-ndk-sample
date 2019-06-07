package ru.madbrains.ndksample

import android.app.Application

/**
 * @author2 Artem Budarin
 * Created on 20/03/2019.
 */
class App : Application() {

    companion object {
        lateinit var instance: App
    }

    override fun onCreate() {
        super.onCreate()
        instance = this
    }

}