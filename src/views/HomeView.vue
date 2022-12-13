<template>
  <div class="flex flex-col gap-6">
    <section>
      <h1>Squatty</h1>
      <h3>The squatting car</h3>
    </section>

    <section
      class="grid gap-4"
      :class="{ 'hidden transition-all': isCameraOpen }"
    >
      <h2>This challenge requires 2 players.</h2>
      <h3>
        Position yourself towards the camera and start squatting to move the
        car. The faster you squat, the faster the car moves. First to reach the
        finish line wins!
      </h3>
    </section>

    <section
      class="grid gap-4"
      :class="{ 'translate-y-0 transition-all': isCameraOpen }"
    >
      <div class="text-center border-dashed border-2 p-2 font-bold rounded-xl">
        Squat Count: {{ scount }}
      </div>
      <div
        class="flex flex-col-reverse rounded-2xl gap-6 p-4 min-h-max border-dashed border-2"
      >
        <div class="flex justify-center items-center">
          <div class="camera-button">
            <button
              type="button"
              class="bg-slate-300 p-4 rounded-2xl hover:scale-90 transition-transform"
              @click="toggleCamera"
            >
              <span v-if="!isCameraOpen" class="flex gap-4 items-center">
                <img src="../assets/icons/ic_camera.svg" />
                <h3>Start Camera</h3>
              </span>
              <span v-else class="flex gap-4 items-center">
                <img src="../assets/icons/ic_camera_close.svg" />
                <h3>Stop Camera</h3>
              </span>
            </button>
          </div>
        </div>
        <div v-if="isCameraOpen">
          <img
            src="http://localhost:5000/video_feed"
            class="w-full object-cover rounded-xl"
          />
        </div>
        <div class="w-full h-96 bg-black rounded-xl" v-else></div>
      </div>
    </section>
  </div>
</template>

<script>
// @ is an alias to /src
import axios from "axios";

export default {
  name: "HomeView",
  data() {
    return {
      msg: 0,
      scount: 0,
      polling: null,
      isCameraOpen: false,
    };
  },
  methods: {
    getMessage() {
      const path = "http://localhost:5000/data";
      axios
        .get(path)
        .then((res) => {
          this.msg = res.data.count;
          // console.log(this.msg);
        })
        .catch((error) => {
          console.error(error);
        });
    },
    pollData() {
      this.polling = setInterval(() => {
        this.getMessage();
        this.updateCount();
      }, 10);
    },
    toggleCamera() {
      if (this.isCameraOpen) {
        this.isCameraOpen = false;
        axios
          .post("http://localhost:5000/video_feed")
          .then((res) => {})
          .catch((error) => {
            console.log(error);
          });
        this.msg = 0;
        this.scount = 0;
      } else {
        this.isCameraOpen = true;
      }
    },
    async updateCount() {
      const headers = { "Content-Type": "application/json;charset=UTF-8" };
      const path = "http://172.20.10.2/switch_on"; // http://172.20.10.2/switch_on_2 for player 2
      if (this.scount != this.msg) {
        this.scount = this.msg;
        await axios
          .post(path, null, { headers })
          .then((res) => {})
          .catch((error) => {
            console.log(error);
          });
      }
    },
  },
  created() {
    this.pollData();
  },
  beforeDestroy() {
    clearInterval(this.polling);
  },
};
</script>
